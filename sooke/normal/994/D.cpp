#include <cstdio>
#include <cstring>

int n , m , a1[13] , a2[13] , b1[13] , b2[13]; 
bool pos[10] , ppos[10];

inline int Get(int u , int v){
	if(a1[u] == b1[v] && a2[u] == b2[v])
		return 0;
	if(a1[u] == b2[v] && a2[u] == b1[v])
		return 0;
	if(a1[u] == b1[v])
		return a1[u];
	if(a1[u] == b2[v])
		return a1[u];
	if(a2[u] == b1[v])
		return a2[u];
	if(a2[u] == b2[v])
		return a2[u];
	return 0;
}

inline int Count(){
	int cnt = 0;
	for(int i = 1 ; i <= 9 ; i++)
		cnt += pos[i];
	return cnt;
}
inline int _Count(){
	int cnt = 0;
	for(int i = 1 ; i <= 9 ; i++)
		cnt += ppos[i];
	return cnt;
}

int main(){
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d%d" , &a1[i] , &a2[i]);
	for(int i = 1 ; i <= m ; i++)
		scanf("%d%d" , &b1[i] , &b2[i]);
	for(int i = 1 ; i <= n ; i++){
		memset(pos , false , sizeof(pos));
		for(int j = 1 ; j <= m ; j++){
			int res = Get(i , j);
			pos[res] = true;
			ppos[res] = true;
		}
		int cnt = Count();
		if(cnt > 1){
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 1 ; i <= m ; i++){
		memset(pos , false , sizeof(pos));
		for(int j = 1 ; j <= n ; j++){
			int res = Get(j , i);
			pos[res] = true;
			ppos[res] = true;
		}
		int cnt = Count();
		if(cnt > 1){
			printf("-1\n");
			return 0;
		}
	}
	int cnt = _Count();
	if(cnt > 1)
		printf("0\n");
	else
		for(int i = 1 ; i <= 9 ; i++)
			if(ppos[i])
				printf("%d\n" , i);
	return 0;
}

// By Sooke.
// CF993B Open Communication.