#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200010;
struct Node{
	int left, right, mid, type;
	Node(){ left = right = mid = 0; type = 1; }
	Node(char *s, char c){
		left = right = mid = 0; 
		int n = strlen(s);
		for(int i = 0; i < n; i++)
			if(s[i] == c) left = i + 1;
			else break;
		for(int i = 0; i < n; i++)
			if(s[n-i-1] == c) right = i + 1;
			else break;
		for(int p = 0, q; p < n; p = q){
			while(p < n && s[p] != c) p++;
			q = p;
			while(q < n && s[q] == c) q++;
			if(q - p > mid) mid = q - p;
		}
		type = left == n;
	}
	Node operator * (const Node &b) const{
		Node r;
		if(b.type){
			r.mid = (mid + 1) * b.mid + mid;
			r.left = (left + 1) * b.mid + left;
			r.right = (right + 1) * b.mid + right;
			r.type = type;
		}
		else{
			r.left = b.left;
			r.right = b.right;
			r.mid = max(b.mid, (mid!=0)*(b.right+1+b.left));
			r.type = 0;
		}
		return r;
	}
};
char s[maxn];
int p[maxn];
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%s", s + p[i]);
		p[i+1] = p[i] + strlen(s + p[i]) + 1;
	}
	int ans = 0;
	for(char c = 'a'; c <= 'z'; c++){
		Node r;
		for(int i = 1; i <= n; i++){
			r = r * Node(s + p[i], c);
//			printf("c:%c i:%d left:%d right:%d mid:%d type:%d\n", c, i, r.left, r.right, r.mid, r.type);
		}
		if(r.mid > ans) ans = r.mid;
	}
	printf("%d\n", ans);
	return 0;
}