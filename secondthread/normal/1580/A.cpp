#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[501][501];
int cs[502][502];

int best,curOffset;
int rangeSum(int x1, int y1, int x2, int y2) {
  x2++;
  y2++;
  return cs[x2][y2]-cs[x1][y2]-cs[x2][y1]+cs[x1][y1];
}
int n0s(int x1, int y1, int x2, int y2) {
  int area=(x2-x1+1)*(y2-y1+1);
  return area-rangeSum(x1, y1, x2, y2);
}
int naive(int x1, int y1, int x2, int y2) {
  return n0s(x1+1, y1, x2-1, y1) + n0s(x1+1, y2, x2-1, y2) + n0s(x1, y1+1, x1, y2-1) + n0s(x2, y1+1, x2, y2-1) + rangeSum(x1+1, y1+1, x2-1, y2-1);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // int T=fs.nextInt();
  int T; cin>>T;
  for (int tt=0; tt<T; tt++) {
    // int h=fs.nextInt(), w=fs.nextInt();
    int h, w; cin>>h>>w;
    // int[][] a=new int[w][h];
    for (int y=0; y<h; y++) {
      string line; cin>>line;
      // char[] line=fs.next().toCharArray();
      for (int x=0; x<w; x++) a[x][y]=line[x]-'0';
    }
    
    // cs=new int[w+1][h+1];
    for (int i=0; i<=500; i++) cs[0][i]=cs[i][0]=0;
    for (int x=1; x<=w; x++)
      for (int y=1; y<=h; y++)
        cs[x][y]=cs[x-1][y]+cs[x][y-1]-cs[x-1][y-1]+a[x-1][y-1];
    
    int ans=1000000000;
    for (int by=4; by<h; by++) {
      
      for (int ty=0; ty<by-3; ty++) {
        best=1000000000;
        int rx=3;
        int toAdd=naive(0, ty, rx, by);
        best=min(best, toAdd-curOffset);
        
        ans=min(ans, best+curOffset);
        for (rx=4; rx<w; rx++) {
          //right col
          curOffset+=n0s(rx, ty+1, rx, by-1)-n0s(rx-1, ty+1, rx-1, by-1);
          //top and bottom
          curOffset+=n0s(rx-1, ty, rx-1, ty) + n0s(rx-1, by, rx-1, by);
          //right middle
          curOffset+=rangeSum(rx-1, ty+1, rx-1, by-1);
          
          toAdd=naive(rx-3, ty, rx, by);
          best=min(best, toAdd-curOffset);
          ans=min(ans, best+curOffset);
        }
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}