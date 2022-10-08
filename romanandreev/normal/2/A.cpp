#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <map>
#include <set>
using namespace std;
int main() {
  //freopen("a.in","r",stdin);
  //freopen("a.out","w",stdout);
  int n;
  scanf("%d",&n);
  int mx=-1;
  string ans;
  map<string, int> mp;
  map<string, int> mp2;
  set<string> st;
  string s[10000];
  int f[10000];
  for (int i=0;i<n;i++){
    cin>>s[i];
    cin>>f[i];
    if (mp.find(s[i])!=mp.end()){
      mp[s[i]]+=f[i];
    } else {
      mp[s[i]]=f[i];
    }
  }
  for (map<string, int>::iterator it=mp.begin();it!=mp.end();it++){
    if ((*it).second>mx){
      mx=(*it).second;
    }
  }
  for (map<string, int>::iterator it=mp.begin();it!=mp.end();it++){
    if ((*it).second==mx){
      st.insert((*it).first);
    }
  }
  for (int i=0;i<n;i++){
    if (mp.find(s[i])!=mp.end()){
      mp2[s[i]]+=f[i];
      if ((mp2[s[i]]>=mx)&&(st.find(s[i])!=st.end())){
        cout<<s[i];
        exit(0);
      }
    } else {
      mp2[s[i]]=f[i];
      if ((mp2[s[i]]>=mx)&&(st.find(s[i])!=st.end())){
        cout<<s[i];
        exit(0);
      }
    }
  }
  return 0;
}