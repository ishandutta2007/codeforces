#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn=300001;
const ll oo=1000000000000000;
int n, x;
ll a[maxn];
ll dp[maxn][3];

ll go(int rightEnd, int rState) {
  if (rightEnd==-1) return 0;
  if (dp[rightEnd][rState]!=-oo) {
//    cout<<"Already seen state "<<rightEnd<<" "<<rState<<'\n';
    return dp[rightEnd][rState];
  }

  ll ans=-oo+1;

  if (rState==0) {
    //using range
    ll bestPrev=0;
    bestPrev=max(bestPrev, go(rightEnd-1, 0));
    bestPrev=max(bestPrev, go(rightEnd-1, 2));
    
    ans=bestPrev+x*a[rightEnd];
  }
  else if (rState==1) {
    //used range
    ll bestPrev=-oo;
    bestPrev=max(bestPrev, go(rightEnd-1, 0));
    bestPrev=max(bestPrev, go(rightEnd-1, 1));

    ans=bestPrev+a[rightEnd];
  }
  else {
    //unused range
    ll bestPrev=0;
    bestPrev=max(bestPrev, go(rightEnd-1, 2));

    ans=bestPrev+a[rightEnd];
  }
 // cout<<"dp["<<rightEnd<<"]["<<rState<<"] = "<<ans<<'\n';
  return dp[rightEnd][rState]=ans;
}

int main() {
  cin>>n>>x;

  for (int i=0; i<n; i++)
    cin>>a[i];

  for (int i=0; i<n; i++)
    for (int j=0; j<3; j++)
      dp[i][j]=-oo;
  ll ans=0;
  for (int rightEnd=0; rightEnd<n; rightEnd++) {
    ans=max(ans, go(rightEnd, 0));
    ans=max(ans, go(rightEnd, 1));
    ans=max(ans, go(rightEnd, 2));
  }
  cout<<ans<<'\n';

  return 0;
}