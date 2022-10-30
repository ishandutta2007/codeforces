#include <bits/stdc++.h>

using namespace std;

class Trie {
	public:
		bool node;
		int n;
		int h;
		vector<Trie*> child;
		
		Trie(int n) {
			int i;
			this->n = n;
			this->h = 0;
			for(i=0; i<n; i++) {
				this->child.push_back(NULL);
			}
			this->node = false;
		}
		
		Trie(int n, int h) {
			int i;
			this->n = n;
			this->h = h;
			for(i=0; i<n; i++) {
				this->child.push_back(NULL);
			}
			this->node = false;
		}
		
		void add(int a) {
			if(32 == h) {
				node = true;
			} else {
				if(child[(a&(1<<(31-h)))!=0] == NULL) {
					child[(a&(1<<(31-h)))!=0] = new Trie(n, h+1);
				}
				child[(a&(1<<(31-h)))!=0]->add(a);
			}
		}
		
		Trie* find(int a, int start) {
			if(start == h) {
				return this;
			}
			if(child[(a&(1<<(start-h-1)))!=0] == NULL) {
				return NULL;
			} else {
				return child[(a&(1<<(start-h-1)))!=0]->find(a, start);
			}
		}
		
		void del() {
			int i;
			for(i=0; i<n; i++) {
				if(child[i] != NULL) {
					child[i]->del();
				}
			}
			delete this;
		}
		
		void print() {
			int first = 1;
			if(node) {
				first = 0;
				printf("\n");
			}
			int i, j;
			for(i=0; i<n; i++) {
				if(child[i] != NULL) {
					if(first) {
						first = 0;
					} else {
						for(j=0; j<h; j++) {
							printf("  ");
						}
					}
					printf("%d ", i);
					child[i]->print();
				}
			}
		}
};

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, q;
	int in;
	scanf("%d %d", &n, &k);
	int a[n];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	if(k == 0) {
		printf("%d\n", n);
		for(i=0; i<n; i++) {
			printf("%d ", i+1);
		}
		printf("\n");
	} else {
		Trie tr(2);
		for(i=0; i<n; i++) {
			tr.add(a[i]);
		}
		map<int, int> idx;
		for(i=0; i<n; i++) {
			idx[a[i]] = i;
		}
		for(i=31; !(k&(1<<i)); i--);
		int d = i;
		map<int, vector<int>> answer;
		for(i=0; i<n; i++) {
			int num = answer.count(a[i]>>(d+1));
			if(num == 0) {
				answer[a[i]>>(d+1)] = {i};
			} else if(num == 2) {
				continue;
			}
			Trie* p = tr.find(a[i]>>(d+1), 32-(d+1));
			//printf("%p", p);
			int max_xor = 0;
			for(j=d; j>=0; j--) {
				Trie* next = p->child[!(a[i]&(1<<j))];
				if(next == NULL) {
					//printf("?");
					next = p->child[(a[i]&(1<<j))!=0];
				} else {
					max_xor += (1<<j);
				}
				p = next;
				//printf("!");
				//printf("%p", p);
			}
			if(max_xor >= k && max_xor != 0) {
				answer[a[i]>>(d+1)] = {i, idx[max_xor^a[i]]};
			}
		}
		int count = 0;
		for(auto v:answer) {
			count += v.second.size();
		}
		if(count < 2) {
			printf("-1\n");
		} else {
			printf("%d\n", count);
			for(auto v:answer) {
				//printf("%d ", v.first);
				for(i=0; i<v.second.size(); i++) {
					printf("%d ", v.second[i]+1);
				}
				//printf("\n");
			}
			printf("\n");
		}
	}
}