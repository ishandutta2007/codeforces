// Can U hack it?

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

const int maxn=2e5+10,SQ=500;

vector<int>v[SQ],ans,img,vec,sp,od;
int a[maxn],lz[SQ];

pair<vector<int>,bool> f(vector<int>v){
    ans.clear();img.clear();sp.clear();od.clear();
    int gd=-1;
    for(int x:v){
	int cop=x,o=0;
	for(int i=0;i<sz(ans);i++){
	    if(bit(cop,sp[i]))
		cop^=img[i],o^=od[i];
	}
	if(cop==0){
	    if(o==0) gd=x;
	}
	else{
	    o^=1;
	    int bt=__builtin_ctz((cop & -cop));
	    for(int i=0;i<sz(ans);i++){
		if(bit(img[i],bt))
		    img[i]^=cop,od[i]^=o;
	    }
	    ans.PB(x);
	    img.PB(cop);
	    sp.PB(bt);
	    od.PB(o);
	}
    }
    if(gd==-1)
	return {ans,0};
    ans.PB(gd);
    return {ans,1};
}

int main(){
    int n,q;scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
	v[i/SQ].PB(a[i]);
    }
    for(int i=0;i<SQ;i++)
	v[i]=f(v[i]).F;
    while(q--){
	int task,l,r;scanf("%d%d%d",&task,&l,&r);
	l--;r--;
	if(task==1){
	    int x;scanf("%d",&x);
	    for(int i=(l/SQ);i<=(r/SQ);i++){
		if((i*SQ)<l || r<(i*SQ+SQ-1)){
		    v[i].clear();
		    for(int j=(i*SQ);j<min(n,(i*SQ+SQ));j++){
			a[j]^=lz[i];
			if(l<=j && j<=r) a[j]^=x;
			v[i].PB(a[j]);
		    }
		    lz[i]=0;
		    v[i]=f(v[i]).F;
		}
		else{
		    lz[i]^=x;
		}
	    }
	}
	else{
	    vec.clear();
	    for(int i=(l/SQ);i<=(r/SQ);i++){
		if((i*SQ)<l || r<(i*SQ+SQ-1)){
		    for(int j=max(l,(i*SQ));j<min(r+1,(i*SQ+SQ));j++)
			vec.PB(a[j]^lz[i]);
		}
		else{
		    for(int x:v[i])
			vec.PB(x^lz[i]);
		}
	    }
	    auto pp=f(vec);
	    int ans=sz(pp.F)-pp.S;
	    ans=(1<<ans);
	    printf("%d\n",ans);
	}
    }
}