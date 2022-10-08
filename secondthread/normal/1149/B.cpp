#include <bits/stdc++.h>

const int maxn=100002;
const int maxLen=251;
using namespace std;

//nextIndexOf[i][j] returns the next index of [i] after index j
int nextIndexOf[26][maxn+1];
int minEnd[maxLen][maxLen][maxLen];
vector<int> a, b, c;

void recalc(int ind1, int ind2, int ind3) {
  if (ind1==0&&ind2==0&&ind3==0) {
    minEnd[ind1][ind2][ind3]=-1;
    return;
  }
  int case1=maxn, case2=maxn, case3=maxn;
  int minOld;
  if (ind1!=0) {
    minOld=minEnd[ind1-1][ind2][ind3];
    case1=nextIndexOf[a[ind1-1]][minOld+1];
//    cout<<"\t next char: "<<a[ind1-1]<<" minOld: "<<minOld<<endl;
  }
  if (ind2!=0) {
    minOld=minEnd[ind1][ind2-1][ind3];
    case2=nextIndexOf[b[ind2-1]][minOld+1];
  }
  if (ind3!=0) {
    minOld=minEnd[ind1][ind2][ind3-1];
    case3=nextIndexOf[c[ind3-1]][minOld+1];
  }

 // cout<<"recalculated "<<ind1<<" "<<ind2<<" "<<ind3<<" to be: min of "<<case1<<" "<<case2<<" "<<case3<<endl;
  minEnd[ind1][ind2][ind3]=min(min(case1, case2), case3);
}

int main() {
  //TODO: fastio
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, Q;
  cin>>n>>Q;
  string str;
  cin>>str;

  //precomp nextIndexOf
  for (int i=0; i<26; i++)
    nextIndexOf[i][n]=nextIndexOf[i][n+1]=n;

  int nextIndex[26];
  for (int i=0; i<26; i++)
    nextIndex[i]=n;

  for (int i=n-1; i>=0; i--) {
    nextIndex[str[i]-'a']=i;
    for (int c=0; c<26; c++) {
      nextIndexOf[c][i]=nextIndex[c];
  //    cout<<"next index of "<<c<<" "<<i<<" = "<<nextIndexOf[c][i]<<endl;
    }
  }
  minEnd[0][0][0]=-1;
  for (int qq=0; qq<Q; qq++) {
    string type;
    int religion;
    char toAdd;
    cin>>type;
    if (type=="+") {
      cin>>religion>>toAdd;
      toAdd-='a';
      religion--;
      if (religion==0) {
        a.push_back(toAdd);
        for (int bi=0; bi<=b.size(); bi++) {
          for (int ci=0; ci<=c.size(); ci++) {
            recalc(a.size(), bi, ci);
          }
        }
      }
      if (religion==1) {
        b.push_back(toAdd);
        for (int ai=0; ai<=a.size(); ai++) {
          for (int ci=0; ci<=c.size(); ci++) {
            recalc(ai, b.size(), ci);
          }
        }
      }
      if (religion==2) {
        c.push_back(toAdd);
        for (int ai=0; ai<=a.size(); ai++) {
          for (int bi=0; bi<=b.size(); bi++) {
            recalc(ai, bi, c.size());
          }
        }
      }
    }
    else {
      cin>>religion;
      religion--;
      if (religion==0)
        a.pop_back();
      if (religion==1)
        b.pop_back();
      if (religion==2)
        c.pop_back();
    }
    
    if (minEnd[a.size()][b.size()][c.size()]<n) {
      cout<<"YES\n";
    }
    else {
      cout<<"NO\n";
    }
  }
  return 0;
}