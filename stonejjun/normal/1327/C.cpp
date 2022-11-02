#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> v[101010];
ll chk[101010];
ll go[101010];
stack<char> s;
int main()
{
   ll n,m,k,a,b,c,i,j;
   scanf("%lld %lld %lld",&n,&m,&k);
   for(i=1;i<=2*k;i++)
   	scanf("%lld %lld",&a,&b);

   printf("%lld\n",2*n*m-2);
   for(i=1;i<m;i++){
   		printf("L");
   		s.push('R');
   }
   for(i=2;i<=n;i++){
   	printf("D");
   	s.push('U');
   	if(i%2==0){
   		for(j=1;j<m;j++){
   			printf("R");
   			s.push('L');
   		}
   	}
   	else{
   		for(j=1;j<m;j++){
   		printf("L");
   		s.push('R');
  	 }
   	}
   }
   while(!s.empty()){
   	printf("%c",s.top());
   	s.pop();
   }
}