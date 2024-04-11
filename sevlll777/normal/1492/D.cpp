#line 1 "/Users/lynmisakura/kyopro/library_cp/template.cpp"
#include<bits/stdc++.h>
#line 3 "/Users/lynmisakura/kyopro/library_cp/template.cpp"
using namespace std;
#define REP(i,n) for(int i = 0;i < n;i++)
#define RNG(i,s,n) for(int i = s;i <= n;i++)
#define _RNG(i,e,s) for(int i = e;i >= s;i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define dup(x,y) (x + y - 1) / (y)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define lb(x,key) lower_bound(all(x) , (key))
#define ub(x,key) upper_bound(all(x) , (key))
#define _size(v) int((v).size())

template<class T> bool chmax(T& a,T b){ if(a < b){ a = b; return true; }else return false; }
template<class T> bool chmin(T& a,T b){ if(a > b){ a = b; return true; }else return false; }

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;

#define debug(arr) cout << #arr << " = " << arr << '\n'
#define debug2(a,b) cout<<"["<<#a<<","<<#b<<"] = "<<"["<<a<<","<<b<<"]\n"
#define debug3(a,b,c) cout<<"["<<#a<<","<<#b<<","<<#c<<"] = "<<"["<<a<<","<<b<<","<<c<<"]\n"
template<class T> ostream &operator << (ostream& out, const vector<T>& arr) {
    cout << "{"; for (int i = 0; i < arr.size(); i++)cout << (!i ? "" : ", ") << arr[i]; cout << "}";
    return out;
}
template<class T> ostream &operator << (ostream& out, const vector<vector<T> >& arr) {
    cout << "{\n"; for (auto& vec : arr)cout << "  " << vec << ",\n"; cout << "}";
    return out;
}
template<class S,class T> ostream &operator << (ostream& out, const pair<S,T>& p){
    cout << "{" << p.first << "," << p.second << "}" << '\n';
    return out;
}
template<class T> istream &operator >> (istream& in, vector<T>& arr) {
    for (auto& i : arr)cin >> i; return in;
}
template<class S,class T> istream &operator >> (istream& in,pair<S,T>& p){
    cin >> p.first >> p.second; return in;
}

#define F first
#define S second
/////////////////////////////////////////////////////////////////////////
namespace cp{
    void iob(){ cin.tie(0); ios::sync_with_stdio(false); }
}
#line 2 "combined.cpp"

int a,b,k;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> a >> b >> k;
    if(k == 0){
	cout << "Yes" << '\n';
	string x = "",y = "";
	x += '1';
	b--;
	for(int i=0;i<a;i++) x += '0';
	for(int i=0;i<b;i++) x += '1';
	cout << x << '\n';
	cout << x << '\n';
	return 0;
    }
    k--;
    if(a > 0 && b >= 2 && (a + b - 3 >= k)){
	cout << "Yes" << '\n';

	string x = "";
	string y = "";

	a--;
	b-=2;

	x += '1';
	y += '1';

	x += '1';
	y += '0';
	for(int i=0;i<k;i++){
	    if(a){
		a--;
		x += '0';
		y += '0';
	    }else{
		b--;
		x += '1';
		y += '1';
	    }
	}
	x += '0';
	y += '1';
	while(a--){
	    x += '0';
	    y += '0';
	}
	while(b--){
	    x += '1';
	    y += '1';
	}

	cout << x << '\n';
	cout << y << '\n';

    }else{
	cout << "No" << '\n';
    }

}