#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
const int maxn=200002;

int a[maxn];
int indexOf[maxn];
int higherToRight[maxn];
int higherToLeft[maxn];
ii vals[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>>n;
  for (int i=0; i<n; i++) {
    cin>>a[i];
    indexOf[a[i]]=i;
    vals[i]={a[i], i};
  }
  sort(vals, vals+n);

  set<int> seenIndexes;

  ll total=0;
  for (int i=n-1; i>=0; i--) {
    int nextInd=vals[i].second;
    seenIndexes.insert(nextInd);
    auto it=seenIndexes.upper_bound(nextInd);
    higherToRight[nextInd]=(it==seenIndexes.end()?n:(*it));

    it=seenIndexes.lower_bound(nextInd);
    higherToLeft[nextInd]=(it==seenIndexes.begin()?-1:(*(--it)));

    //printf("checking index: %d, higherToLeft: %d, higherToRight: %d\n", nextInd, higherToLeft[nextInd]
    //    , higherToRight[nextInd]);

    int leftBound=higherToLeft[nextInd]+1, rightBound=higherToRight[nextInd]-1;
    int leftSize=nextInd-leftBound, rightSize=rightBound-nextInd;
    if (leftSize<rightSize) {
      for (int l=leftBound; l<nextInd; l++) {
        if (a[l]>=a[nextInd]) continue;
        int rVal=a[nextInd]-a[l];
        int r=indexOf[rVal];
        if (r>nextInd&&r<=rightBound)
          total++;
      }
    }
    else {
      for (int r=nextInd+1; r<=rightBound; r++) {
        if (a[r]>=a[nextInd]) continue;
        int lVal=a[nextInd]-a[r];
        int l=indexOf[lVal];
        if (l<nextInd&&l>=leftBound)
          total++;
      }
    }
  }

  cout<<total<<endl;

  return 0;
}