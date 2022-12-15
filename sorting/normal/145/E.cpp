#include <bits/stdc++.h>

using namespace std;

template<size_t k_Size>
class Segment_Tree{
private:
    struct Node{
        int cnt_4, cnt_7;
        int decreasing, increasing;

        Node(){}

        Node(int value){
            if(value == 4){
                cnt_4 = 1;
                cnt_7 = 0;
            }
            else{
                assert(value == 7);
                cnt_4 = 0;
                cnt_7 = 1;
            }

            decreasing = increasing = 1;
        }

        Node(int cnt_4, int cnt_7, int decreasing, int increasing){
            this->cnt_4 = cnt_4;
            this->cnt_7 = cnt_7;

            this->decreasing = decreasing;
            this->increasing = increasing;
        }

        friend Node merge(const Node &lvalue, const Node &rvalue){
            Node answer;

            answer.cnt_4 = lvalue.cnt_4 + rvalue.cnt_4;
            answer.cnt_7 = lvalue.cnt_7 + rvalue.cnt_7;

            answer.decreasing = max(lvalue.cnt_7 + rvalue.decreasing, lvalue.decreasing + rvalue.cnt_4);
            answer.increasing = max(lvalue.cnt_4 + rvalue.increasing, lvalue.increasing + rvalue.cnt_7);

            return answer; 
        }
    };
private:
    Node nodes[4 * k_Size];
    int n;
    bool lazy[4 * k_Size];
private:
    void initialise(int index, int l, int r, const string &rvalue){
        if(l == r){
            nodes[index] = (rvalue[l] - '0');
            lazy[index] = 0; 
            return;
        }

        int mid = l + (r - l) / 2;

        initialise(2 * index + 1, l, mid, rvalue);
        initialise(2 * index + 2, mid + 1, r, rvalue);

        nodes[index] = merge(nodes[2 * index + 1], nodes[2 * index + 2]);
        lazy[index] = 0;
    }

    void push_lazy(int index, int l, int r){
        if(!lazy[index])
            return;

        if(l != r){
            lazy[2 * index + 1] ^= lazy[index];
            lazy[2 * index + 2] ^= lazy[index];
        }

        swap(nodes[index].cnt_4, nodes[index].cnt_7);
        swap(nodes[index].increasing, nodes[index].decreasing);

        lazy[index] = 0;
    } 

    void switch_range(int index, int l, int r, int sl, int sr){
        push_lazy(index, l, r);

        if(l > sr || r < sl)
            return;
        if(sl <= l && r <= sr){
            lazy[index] = 1;
            push_lazy(index, l, r);
            return;
        }

        int mid = l + (r - l) / 2;

        switch_range(2 * index + 1, l, mid, sl, sr);
        switch_range(2 * index + 2, mid + 1, r, sl, sr);

        nodes[index] = merge(nodes[2 * index + 1], nodes[2 * index + 2]);
    }

    int get_length_of_longest_non_decreasing_sequence(int index, int l, int r){
        push_lazy(index, l, r);
        
        return nodes[index].increasing;     
    }
public:
    Segment_Tree(){}

    void operator=(const string &rvalue){
        n = rvalue.size();
        initialise(0, 0, n - 1, rvalue);
    }

    void switch_range(int l, int r){
        switch_range(0, 0, n - 1, l, r);
    }

    int get_length_of_longest_non_decreasing_sequence(){
        return get_length_of_longest_non_decreasing_sequence(0, 0, n - 1);
    }
};

const int k_N = 1e6 + 3;

int n, m;
string s;
Segment_Tree<k_N> segment_tree;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> s;

    segment_tree = s;

    for(int i = 0; i < m; ++i){
        string type;
        cin >> type;

        if(type == "switch"){
            int l, r;
            cin >> l >> r;

            --l, --r;

            segment_tree.switch_range(l, r);
            continue;
        }

        assert(type == "count");
        cout << segment_tree.get_length_of_longest_non_decreasing_sequence() << "\n";
    }
}