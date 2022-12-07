#include<bits/stdc++.h>
#define P make_pair
#define Y second
#define F pair<int,int>
using namespace std;
int n,m,r,k,A,B,C,D,S[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
double Q;
map<F,bool>s;
priority_queue<pair<long long,F> >O;
long long W(int x,int y){return 1LL*(min(x,n-r+1)-max(1,x-r+1)+1)*(min(y,m-r+1)-max(1,y-r+1)+1);}
int main() {
	scanf("%d%d%d%d",&n,&m,&r,&k);
	A=(n+1)/2,B=(m+1)/2;
	O.push(P(W(A,B),P(A,B)));
	s[P(A,B)]=1;
	while(k--) {
		A=O.top().Y.first;B=O.top().Y.Y;
		Q+=O.top().first;
		O.pop();
		for(int i=0;i<4;i++) {
			C=A+S[i][0],D=B+S[i][1];
			if(!s[P(C,D)])O.push(P(W(C,D),P(C,D))),s[P(C,D)]=1;
		}
	}
	printf("%.15f\n",Q/(n-r+1)/(m-r+1));
}