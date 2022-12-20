// Wanna Hack? GL...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=3e5+10,inf=1e9;

string s[maxn];
char ch[4]={'A','C','G','T'},Ac1[4],Ac2[4];
bool arr1[maxn],arr2[maxn],tmp[maxn];
int An1=inf,An2=inf;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
	cin>>s[i];
    }
    do{
	int cnt=0;
	for(int i=0;i<n;i++){
	    int aa=0,bb=0;
	    for(int j=0;j<m;j++)
		aa+=(s[i][j]!=ch[(i&1)*2+(j&1)]);
	    for(int j=0;j<m;j++)
		bb+=(s[i][j]!=ch[(i&1)*2+((j&1)^1)]);
	    if(aa<bb) tmp[i]=0;
	    else      tmp[i]=1;
	    cnt+=min(aa,bb);
	}
	if(An1>cnt) An1=cnt,memcpy(Ac1,ch,sizeof ch),memcpy(arr1,tmp,sizeof tmp);
    }while(next_permutation(ch,ch+4));
    do{
	int cnt=0;
	for(int j=0;j<m;j++){
	    int aa=0,bb=0;
	    for(int i=0;i<n;i++)
		aa+=(s[i][j]!=ch[(i&1)*2+(j&1)]);
	    for(int i=0;i<n;i++)
		bb+=(s[i][j]!=ch[((i&1)^1)*2+(j&1)]);
	    if(aa<bb) tmp[j]=0;
	    else      tmp[j]=1;
	    cnt+=min(aa,bb);
	}
	if(An2>cnt) An2=cnt,memcpy(Ac2,ch,sizeof ch),memcpy(arr2,tmp,sizeof tmp);
    }while(next_permutation(ch,ch+4));
    if(An1<An2){
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++)
		cout<<Ac1[(i&1)*2+((j&1)^arr1[i])];
	    cout<<"\n";
	}
    }
    else{
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++)
		cout<<Ac2[((i&1)^arr2[j])*2+(j&1)];
	    cout<<"\n";
	}
    }
    return 0;
}