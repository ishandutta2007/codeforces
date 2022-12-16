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

const int eight=1e8,Max=1e4;

vector<int>vec,ansx,ansy;

int Ask(int a,int b){
    cout<<"0 "<<a<<" "<<b<<endl;
    int ans;cin>>ans;
    return ans;
}
void Ans(){
    cout<<"1 "<<sz(ansx)<<" "<<sz(ansy)<<endl;
    for(int x:ansx)
	cout<<x<<" ";
    cout<<endl;
    for(int y:ansy)
	cout<<y<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    vec.PB(-eight+Ask(-eight,-eight));
    int hg=eight-Ask(eight,eight);
    while(vec.back()!=hg){
	int num=1;
	while(true){
	    int num2=Ask(vec.back()+num,vec.back()+num);
	    if(num2!=num){
		vec.PB(vec.back()+num+num2);
		break;
	    }
	    num*=2;
	}
    }
    int no=0;
    if(vec[0]!=-eight) no=-eight;
    if(vec.back()!=eight) no=eight;
    for(int i=0;i<sz(vec)-1;i++){
	if(vec[i]+1!=vec[i+1])
	    no=vec[i]+1;
    }
    for(int x:vec){
	if(sz(ansx)<Max && Ask(x,no)==0)
	    ansx.PB(x);
	else
	    ansy.PB(x);
    }
    random_shuffle(ansx.begin(),ansx.end());
    for(int x:ansx){
	if(sz(ansy)<Max && Ask(no,x)==0)
	    ansy.PB(x);
    }
    Ans();
    return 0;
}