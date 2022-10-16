#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <cstring>
using namespace std;
unordered_map<char,int> mp;
int t,n,pos[55];
char ans[55];
queue<int> q2,q;
bool vis[55];
string s;
signed main(){
  cin >> t;
  while(t--){
    cin >> s >> n;
    unordered_map<char,int> tmp;
    memset(vis,0,sizeof(vis));
    swap(tmp,mp);//O(1) mp.clear()O(n)
    for (int i : s) mp[i-96]++;//
    for (int i=0;i<n;i++) {
      cin >> pos[i];
      if (pos[i]==0) q2.push(i),vis[i] = true;//0
    }
    swap(q,q2);
    int curr = 26;
    while(mp[curr]<q.size()) curr--;
    while(!q.empty()){
      int qf = q.front(); q.pop();
      for (int i=0;i<n;i++) {
        if (vis[i]) continue;
        pos[i]-=abs(qf-i);
        if (pos[i]==0) q2.push(i),vis[i] = true;
      }
      ans[qf] = curr;
      if (q.empty()) {
        swap(q,q2);
        curr--;
        while(mp[curr]<q.size() && curr!=0) curr--;
       
      }
    }
    for (int i=0;i<n;i++) cout << char(ans[i]+96);
    cout << endl;
  }
}