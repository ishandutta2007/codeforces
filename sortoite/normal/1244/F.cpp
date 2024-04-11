#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;
template<typename T, typename U> inline void smin(T &a, const U &b) {if (a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if (a<b) a=b;}

inline int power(int a, int b, int m, int ans=1) {
  for(; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
  return ans;
}

const int NN = 2e5+10;

int a[NN<<2];
char s[NN];

int n;
void print() {
	for(int i=0; i<n; i++) putchar(a[i]?'W':'B');
	puts("");
	exit(0);
}

int L[NN], R[NN], m;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  int k;
  cin>>n>>k;
  scanf("%s", s);
  for(int i=0; i<n; i++) a[i]= a[i+n] = a[i+n+n] =('W' == s[i]);
  
  int dif=0;
  for(int i=1; i<n; i++) if(a[i] != a[0]) dif=1;
  if(dif == 0) print();
  
  int root=-1;
  for(int i=0; i<n; i++) {
  	if(a[i]!=a[i+1] && a[i+2] == a[i+1]) {
  		root=(i+1)%n;
  		break;
  	}
  }
  
  if(root == -1) {
  	if(k&1) for(int i=0; i<n; i++) a[i]^=1;
  	print();
  }
  
  m=0;
  for(int i=root, j; i<root+n; i=j) {
  	for(j=i; a[j] == a[i]; j++);
  	L[m]=i;
  	R[m]=j-1; m++;
  	while(j<root+n && a[j+1]!=a[j]) j++;
  }
  
//  for(int i=0; i<m; i++) cout<<L[i]<<' '<<R[i]<<endl;
//  exit(0);
  
  L[m]=L[0]+n;
  R[m]=R[0]+n;
  
  for(int i=0; i<m; i++) {
  	int md=(R[i]+L[i+1])/2;
  	for(int j=R[i]+1; j<=md; j++) {
  		if(j-R[i]<=k) {
  			a[j%n]= a[L[i]];
  		}else if(k&1) {
  			a[j%n]^=1;
  		}
  	}
  	for(int j=L[i+1]-1; j>md; j--) {
  		if(L[i+1]-j<=k) {
  			a[j%n]=a[L[i+1]];
  		}else if(k&1) {
  			a[j%n]^=1;	
  			
  		}
  	}
  }
  print();
  return 0;
}