#include <cstdio>
#include <algorithm>
#define Maxn 100005

using namespace std;

struct Knight{
	int i , p , c;
	long long ans;
};

bool Cmp(int a , int b){
	return a > b;
}
bool Cmpp(Knight a , Knight b){
	return a.p < b.p;
}
bool Cmpi(Knight a , Knight b){
	return a.i < b.i;
}

Knight S[Maxn];
int n , m , r = 1 , j , f[15];

inline void Update(){
	sort(f + 1 , f + j + 1 , Cmp);
}

int main(){
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d" , &S[i].p);
		S[i].i = i;
	}
	for(int i = 1 ; i <= n ; i++){
		scanf("%d" , &S[i].c);
		S[i].ans = S[i].c;
	}
	sort(S + 1 , S + n + 1 , Cmpp);
	for(int i = 1 ; i <= n ; i++){
		while(true){
			if(S[r].p >= S[i].p)
				break;
			if(j == m + 1)
				f[j] = S[r].c;
			else
				f[++j] = S[r].c;
 			Update();
			r++;
		}
		for(int k = 1 ; k <= m ; k++)
			S[i].ans += f[k];
	}
	sort(S + 1 , S + n + 1 , Cmpi);
	for(int i = 1 ; i < n ; i++)
		printf("%I64d " , S[i].ans);
	printf("%I64d\n" , S[n].ans);
	return 0;
}

// By Sooke.
// CF994B Knights of a Polygonal Table.