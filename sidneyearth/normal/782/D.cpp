#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1010;
char first[maxn][30], second[maxn][30];
int head[2 * maxn], mark[2 * maxn], S[2 * maxn];
int e_cnt = 0, top = 0;
struct Edge{
	int v, nxt;
}e[200010];
void Add(int u, int v){
	int id = e_cnt++;
	e[id].v = v;
	e[id].nxt = head[u];
	head[u] = id;
}
bool DFS(int u){
	if(mark[u^1]) return false;
	if(mark[u]) return true;
	mark[S[top++] = u] = true;
	for(int id = head[u]; id != -1; id = e[id].nxt)
		if(!DFS(e[id].v)) return false;
	return true;
}
bool TwoSat(int n){
	for(int i = 0; i < 2 * n; i += 2){
		if(mark[i] || mark[i+1]) continue;
		top = 0;
		if(!DFS(i)){
			while(top) mark[S[--top]] = false;
			if(!DFS(i+1)) return false;
		}
	}
	return true;
}
bool IsDif(char *s, char *t){
	for(int i = 0; i < 3; i++)
		if(s[i] != t[i]) return true;
	return false;
}
int main(){
	int n; scanf("%d", &n);
	for(int i = 0; i < 2 * n; i++)
		head[i] = -1;
	for(int i = 0; i < n; i++){
		scanf("%s%s", first[i], second[i]);
		second[i][3] = 0;
		second[i][2] = second[i][0];
		second[i][1] = first[i][1];
		second[i][0] = first[i][0];
		first[i][3] = 0;
	}
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++){
			if(strcmp(first[i], first[j]) == 0){
				Add(2*i, 2*i+1);
				Add(2*j, 2*j+1);
			}
			if(strcmp(first[i], second[j]) == 0){
				Add(2*i, 2*j);
				Add(2*j+1, 2*i+1);
			}
			if(strcmp(second[i], first[j]) == 0){
				Add(2*j, 2*i);
				Add(2*i+1, 2*j+1);
			}
			if(strcmp(second[i], second[j]) == 0){
				Add(2*j+1, 2*i);
				Add(2*i+1, 2*j);
			}
		}
	if(TwoSat(n)){
		printf("YES\n");
		for(int i = 0; i < n; i++)
			printf("%s\n", mark[2*i] ? first[i] : second[i]);
	}
	else
		printf("NO\n");
	return 0;
}