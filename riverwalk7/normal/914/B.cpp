#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100010
#define scd(x) scanf("%d",&x);
#define prd(x) printf("%d\n",x);
#define scl(x) scanf("%lld",&x);
#define prl(x) printf("%lld",x);
ll MOD =1000000007;
#define INF 100000000
#define FOR(i,k,s) for (int i=s ; i<k ; i++)
#define RFOR(i,k,e) for (int i=k ; i>=e ; i--)
double epsilon = 0.00001;
double PI = 3.1415926535897932384626433832795028841971693993;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector< pii > vpi;
typedef vector< pll > vpl;
// struct node{
// 	int a;
// 	int b;
// };
// vi adj[N];
// // // vi adjr[N];
// int visited[N];
// // vi v;
// int count1=0;
// void dfs(int r){
// 	visited[r] = 1;
// 	FOR(i,adj[r].size()){

// 		if(visited[adj[r][i]]==0){

// 			dfs(adj[r][i]);
// 		}
// 		else if(visited[i]==1){
// 			count1++;
// 		}
// 	}
// 	visited[r] = 2;
// }
// void dfs2(int r){
// 	visited[r] = 1;
// 	FOR(i,adj[r].size()){

// 		if(visited[adj[r][i]]==0){
// 			visited2[adj[r][i]] += visited2[r];
// 			dfs2(adj[r][i]);
// 		}
// 	}
// 	visited2[r] = 0;
// }
// node tree[4*N];
// node lazy[4*N];
// void SieveOfEratosthenes(int n)
// {
//     bool prime[n+1];
//     memset(prime, true, sizeof(prime));
 
//     for (int p=2; p*p<=n; p++)
//     {

//         if (prime[p] == true)
//         {

//             for (int i=p*2; i<=n; i += p)
//                 prime[i] = false;
//         }
//     }
//     for (int p=2; p<=n; p++)
//        if (prime[p]){
//        	cout << p;
//        }
          
// }
// int phi(int n)
// {
//     float result = n; 
//     for (int p=2; p*p<=n; ++p)
//     {

//         if (n % p == 0)
//         {
//             while (n % p == 0)
//                 n /= p;
//             result *= (1.0 - (1.0 / (float) p));
//         }
//     }
//     if (n > 1)
//         result *= (1.0 - (1.0 / (float) n));
 
//     return (int)result;
// }

int max(int a,int b){
	return (a>b) ? a : b;
}
int max3(int a,int b,int c){
	return (max(a,b)>c) ? max(a,b) : c;
}
int min(int a,int b){
	return (a<b)?a:b;
}
int min3(int a,int b,int c){
	return (min(a,b)<c)?min(a,b):c;
}
// void update(int i, int j , int si , int sj , int index,int x){
// 	if(lazy[index].a!=INT_MIN){
// 		tree[index].a = (sj-si+1)*(lazy[index].a)*(lazy[index].a);
// 		tree[index].b = (sj-si+1)*(lazy[index].a); 
// 		if(si!=sj){
// 			lazy[2*index + 1].a = lazy[index].a;
// 			lazy[2*index + 2].a = lazy[index].a;
// 		}
// 		lazy[index].a = INT_MIN;
// 	}
// 	if(lazy[index].b!=0){
// 		tree[index].a = tree[index].a + (sj-si+1)*(lazy[index].b)*(lazy[index].b) + 2*(lazy[index].b)*(tree[index].b);
// 		tree[index].b = tree[index].b + (sj-si+1)*(lazy[index].b); 
// 		if(si!=sj){
// 			lazy[2*index + 1].b += lazy[index].b;
// 			lazy[2*index + 2].b += lazy[index].b;
// 		}
// 		lazy[index].b = 0;
// 	}
// 	if(j<si || i > sj){
// 	 return ;
//  	}
// 	if(si>=i && sj<=j){

// 		tree[index].a = (sj-si+1)*x*x;
// 		tree[index].b = (sj-si+1)*x;
// 		if(si!=sj){
// 			lazy[2*index + 1].a = x;
// 			lazy[2*index + 2].a = x;

// 		}
// 		return;
		
// 	}

// 	 update(i, j, si , (si + sj)/2 , 2*index + 1,x);
// 	 update( i, j, (si + sj)/2 +1 , sj , 2*index + 2,x);
// 	 tree[index].a = tree[2*index+1].a + tree[2*index+2].a;
// 	 tree[index].b = tree[2*index+1].b + tree[2*index+2].b;	
// }

// int query(int i, int j , int si , int sj , int index){
// 	if(lazy[index].a!=INT_MIN){
// 		tree[index].a = (sj-si+1)*(lazy[index].a)*(lazy[index].a);
// 		tree[index].b = (sj-si+1)*(lazy[index].a); 
// 		if(si!=sj){
// 			lazy[2*index + 1].a = lazy[index].a;
// 			lazy[2*index + 2].a = lazy[index].a;
// 		}
// 		lazy[index].a = INT_MIN;
// 	}
// 	if(lazy[index].b!=0){
// 		tree[index].a = tree[index].a + (sj-si+1)*(lazy[index].b)*(lazy[index].b) + 2*(lazy[index].b)*(tree[index].b);
// 		tree[index].b = tree[index].b + (sj-si+1)*(lazy[index].b); 
// 		if(si!=sj){
// 			lazy[2*index + 1].b += lazy[index].b;
// 			lazy[2*index + 2].b += lazy[index].b;
// 		}
// 		lazy[index].b = 0;
// 	}
// 	if(j<si || i > sj){
// 	 return 0;
//  	}
// 	if(si>=i && sj<=j){
// 		return tree[index].a;
// 	}


// 	return  query(i, j, si , (si + sj)/2 , 2*index + 1)
// 			+ query( i,  j, (si + sj)/2 +1 , sj , 2*index + 2);

// }
// int make_tree(int a[],int i,int j,int index){
// 	if(i==j){
// 		tree[index].a = a[i]*a[i];
// 		return tree[index].a;
// 	}
// 	tree[index].a = make_tree(a,i,(i+j)/2,2*index+1) + make_tree(a,(i+j)/2+1,j,2*index+2);
// 	return tree[index].a;
// }
int main(){
	// std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	// int t;
	// cin >> t;
	// while(t--){
	// }
	int n;
	cin >> n;
	int a[n];
	int hash[100010];
	FOR(i,100010,0){
		hash[i]=0;
	}
	FOR(i,n,0){
		cin >> a[i];
	}
	sort(a,a+n);
	FOR(i,n,0){
		hash[a[i]]++;
	}
	int flag=0;
	for(int i=n-1;i>=0;i--){
		if(hash[a[i]]%2==1){
			flag=1;
			break;
		}
	}
	if(flag==1){
		cout << "Conan";
	}
	else{
		cout << "Agasa";
	}
	return 0;
}