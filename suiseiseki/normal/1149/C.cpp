#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
struct Tree {
	struct Node {
		int delta;
		int min_depth;
		int max_depth;
		int max_lv;
		int max_rv;
		int max_lvr;
		static Node Empty() {
			return Node{0, 0, 0, 0, 0, 0};
		}
		static Node LeftParenthesis() {
			return Node{1, 0, 1, 0, 1, 1};
		}
		static Node RightParenthesis() {
			return Node{-1, -1, 0, 2, 1, 1};
		}
		static Node FromCharacter(char ch) {
			if (ch == '('){
				return LeftParenthesis();
			}
			else{
				return RightParenthesis();
			}
		}
		Node ShiftHeight(int displacement) const {
			return Node{delta + displacement,min_depth + displacement,max_depth + displacement,max_lv - displacement,max_rv - displacement,max_lvr};
		}
		static Node Merge(const Node &lhs,const Node &rhs) {
			Node rhs_shifted=rhs.ShiftHeight(lhs.delta);
			Node result;
			result.delta=rhs_shifted.delta;
			result.min_depth=mn(lhs.min_depth, rhs_shifted.min_depth);
			result.max_depth=mx(lhs.max_depth, rhs_shifted.max_depth);
			result.max_lv=mx(lhs.max_lv,mx(rhs_shifted.max_lv,lhs.max_depth-2*rhs_shifted.min_depth));
			result.max_rv=mx(lhs.max_rv,mx(rhs_shifted.max_rv,rhs_shifted.max_depth-2*lhs.min_depth));
			result.max_lvr=mx(lhs.max_lvr,mx(rhs_shifted.max_lvr,mx(rhs_shifted.max_rv+lhs.max_depth,lhs.max_lv+rhs_shifted.max_depth)));
			return result;
		}
	};
	vector<Node> data;
	int Base;
	Tree(int N) : Base(1) {
		while (Base < N + 1) { Base *= 2; }
		data.resize(Base * 2, Node::Empty());
	}
	void Replace(int pos, char ch) {
		pos += Base;
		data[pos] = Node::FromCharacter(ch);
		pos /= 2;
		while (pos) {
			data[pos] = Node::Merge(data[pos * 2], data[pos * 2 + 1]);
			pos /= 2;
		}
	}
	int GetMaxPath() const {
		return data[1].max_lvr;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	int N, Q;
	string paren_string;
	cin >> N >> Q >> paren_string;
	--N;
	Tree path_tree(N * 2);
	for (int i = 0; i < N * 2; ++i) {
		path_tree.Replace(i, paren_string[i]);
	}
	cout << path_tree.GetMaxPath() << "\n";
	for (int query_idx = 0; query_idx < Q; ++query_idx) {
		int first_swap, second_swap;
		cin >> first_swap >> second_swap;
		--first_swap;
		--second_swap;
		const char next_first = paren_string[second_swap];
		const char next_second = paren_string[first_swap];
		assert(next_first != next_second);
		path_tree.Replace(first_swap, next_first);
		paren_string[first_swap] = next_first;
		path_tree.Replace(second_swap, next_second);
		paren_string[second_swap] = next_second;
		cout << path_tree.GetMaxPath() << "\n";
	}
	return 0;
}