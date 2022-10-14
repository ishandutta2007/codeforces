#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


string intToRoman(int num) 
{   
     // storing roman values of digits from 0-9 
     // when placed at different places
     string m[] = {"", "M", "MM", "MMM"};
     string c[] = {"", "C", "CC", "CCC", "CD", "D", 
                        "DC", "DCC", "DCCC", "CM"};
     string x[] = {"", "X", "XX", "XXX", "XL", "L", 
                        "LX", "LXX", "LXXX", "XC"};
     string i[] = {"", "I", "II", "III", "IV", "V", 
                        "VI", "VII", "VIII", "IX"};
         
     // Converting to roman
     string thousands = m[num/1000];
     string hundereds = c[(num%1000)/100];
     string tens =  x[(num%100)/10];
     string ones = i[num%10];
         
     string ans = thousands + hundereds + tens + ones;
         
     return ans;
}

int solve(){
 	int a;cin>>a;
 	string b;cin>>b;
 	string c;cin>>c;reverse(all(c));
 	int c10=0;
 	int base=1;
 	for(int i=0;i<c.length();i++){
 		int x;
 		if(c[i]>='0' && c[i]<='9')x=c[i]-48;
 		else x=c[i]-65+10;
 		c10+=base*x;base=base*a;
 	}
 	if(b=="R"){
 		cout<<intToRoman(c10)<<endl;
 	}
 	else{
 		int val=0;
 		for(auto i:b){
 			val=val*10+i-48;
 		}
 		vector<char>ans;
 		while(1){
 			int x=c10%val;c10/=val;
 			if(x<=9)ans.pb(x+'0');
 			else ans.pb((x+55));
 			if(c10==0)break;
 		}
 		reverse(all(ans));
 		for(auto i:ans)cout<<i;

 	}
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}