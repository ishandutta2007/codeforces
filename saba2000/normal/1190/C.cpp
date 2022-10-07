#include<bits/stdc++.h>
using namespace std;
int n,k; string s;
string se ="quailty", fi = "tokitsukaze";
vector<int> a,b;
bool ch1(){
    return !a.size() || !b.size();
}
bool ch2(){
    return (b.back() - b[0] + 1 <= k) ||
            (a.back() - a[0] + 1 <= k);
}

bool ch3(){
    if(b.back() - b[0] + 1 > k+1 ||
       a.back() - a[0] + 1 > k+1 ||
       a[0] + 1 > k || b[0] + 1 > k
       || n - a.back() > k || n - b.back() > k) return 0;
        return 1;
}
main(){
   cin >> n >> k;
   cin >> s;
   for(int i = 0; i < s.size(); i++)
    if(s[i] == '0' ) a.push_back(i);
   else b.push_back(i);
   if(ch1()){
        cout<<fi<<endl;
        return 0;
   }
   if(ch2()){
        cout<<fi<<endl;
        return 0;
   }
   if(ch3()){
        cout<<se<<endl;
    return 0;
   }
   cout<<"once again"<<endl;
}
//0