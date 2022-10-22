#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;
Int k, n, a[108000], b;
vector<P> hoge;
set<int> used;
Int cnt[108000], res;
int main(){
  cin >> n >> k;
  for(int i = 0;i < n;i++){
    cin >> a[i];
    cnt[a[i]]++;
    used.insert(a[i]);
  }
  for(int i = 0;i < n;i++){
    cin >> b;
    hoge.push_back(P(b, a[i]));
  }
  sort(hoge.begin(), hoge.end());
  k -= used.size();
  for(int i = 0;i < n;i++){
    if(k == 0)break;
    if(cnt[hoge[i].second] == 1)continue;
    cnt[hoge[i].second]--;
    res += hoge[i].first;
    k--;
  }
  cout << res << endl;
}