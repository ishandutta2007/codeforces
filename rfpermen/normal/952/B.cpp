#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
ll n;
string s;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,0,9){
    	cout<<i<<endl;
    	getline(cin,s);
    	if(s=="don't even"||
		s=="are you serious"||
		s=="worse"||
		s=="terrible"||
		s=="go die in a hole"||
		s=="no way"){
    cout<<"grumpy"<<endl;
    		return 0;
		}
		if(s=="great"||s=="don't think so"||s=="not bad"||s=="cool"||s=="don't touch me"){
			cout<<"normal"<<endl;
    		return 0;
		}
	}
    return 0;
}