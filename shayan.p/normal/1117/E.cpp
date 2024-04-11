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

const int maxn=1e4+10,mod=1e9+7;
const ll inf=1e18;

int id1[maxn],id2[maxn],n;
string ss;
map<int,int>mp;
int f[maxn];

void Do(){
    mp.clear();
    ss.resize(n);
    for(int i=0;i<n;i++){
	int num=id1[i];
	int ch=(mp[num]++)%26;
	id1[i]=26*num+ch;
	ss[i]=char(ch+'a');
    }
    cout<<"? "<<ss<<endl;
    cin>>ss;
    for(int i=0;i<n;i++){
	id2[i]=26*id2[i]+(ss[i]-'a');
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    n=sz(s);
    fill(id1,id1+sz(s),1);
    fill(id2,id2+sz(s),1);
    Do();Do();Do();
    mp.clear();
    for(int i=0;i<n;i++){
	mp[id2[i]]=i;
    }
    for(int i=0;i<n;i++){
	f[mp[id1[i]]]=i;
    }
    ss.resize(n);
    for(int i=0;i<n;i++){
	ss[f[i]]=s[i];
    }
    return cout<<"! "<<ss<<endl,0;
}