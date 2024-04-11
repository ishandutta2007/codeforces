#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

inline int Read(){
	char c = getchar();
	int n = 0;
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		n = (n << 1) + (n << 3) + (c ^ 48) , c = getchar();
	return n;
}

struct Stc{
	int a , b , h;
};

bool Cmp(Stc x , Stc y){
	if(x.b == y.b)
		return x.a > y.a;
	return x.b > y.b;
}

Stc S[100001];
priority_queue < pair < long long , int > > Q;
int n;
long long f[100001] = {0} , ans = 0;

int main(){
	n = Read();
	for(int i = 1 ; i <= n ; i++)
		S[i].a = Read() , S[i].b = Read() , S[i].h = Read();
	sort(S + 1 , S + n + 1 , Cmp);
	ans = f[1] = S[1].h;
	Q.push(make_pair(f[1] , S[1].a));
	for(int i = 2 ; i <= n ; i++){
		while(!Q.empty() && Q.top().second >= S[i].b)
			Q.pop();
		if(Q.empty())
			f[i] = S[i].h;
		else
			f[i] = Q.top().first + S[i].h;
		if(ans < f[i])
			ans = f[i];
		Q.push(make_pair(f[i] , S[i].a));
	}
	printf("%lld\n" , ans);
	return 0;
}