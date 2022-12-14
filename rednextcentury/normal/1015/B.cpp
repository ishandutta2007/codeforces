
#include <bits/stdc++.h>

using namespace std;
#define ll long long
map <ll,ll>ma1,ma;
  ll b[1000000];
int main()
{ ll n ,q, c=0, m=0;
string s,t;
  cin >>n>>s>>t;
  for (int i =0 ; i <n ; i++){
    ma1[s[i]-'a']++;
    ma[t[i]-'a']++;
  }
  for (int i =0 ; i <=26; i ++){
    if (ma1[i]!=ma[i]){
            cout <<-1<<endl;
            return 0;

    }
  }

  for (int i =0 ; i <n ;i++){
      //  cout <<"*"<<endl;

    if (s[i]!=t[i]){
      //  cout <<"i"<<i<<endl;
          //  b[m]=i+1;
          //  m++;
            for (int j =i+1 ; j <n ; j++){
                if (s[j]==t[i]){
                  //  cout <<"j"<<j<<endl;
                    q =j;
                    break;
                }
            }
        c+=(q-i);
        for (int j = q ; j >i ; j--){
         //   cout <<"q"<<j<<endl;
            b[m]=j;
            m++;
            swap(s[j],s[j-1]);
        }
    }
  }

  cout <<c<<endl;
  for (int i =0 ; i <m ; i++){
    cout <<b[i]<<" ";
  }

    return 0;
}