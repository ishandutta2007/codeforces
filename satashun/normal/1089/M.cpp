#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int > id;
int d[108][108];
int D[108][108];
int n, m;
bool come[1080];
int u[] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
int r(int x){
  if(u[x] == x)return x;
  return u[x] = r(u[x]);
}
int unite(int x, int y){
  x = r(x);
  y = r(y);
  u[x] = y;
}

void topo(int x){
  if(come[x])return;
  come[x] = true;
  for(int i = 0;i < n;i++){
    if(D[x][i] == 1)topo(i);
  }
  id.push_back(x);
}

int main(){
  cin >> n;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      cin >> d[i][j];
      if(d[i][j] == 0)d[i][j] = 100;
    }
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      for(int k = 0;k < n;k++){
	d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
      }
    }
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(r(i) == r(j))continue;
      if(d[i][j] < 100 && d[j][i] < 100){
	unite(i, j);
      }
    }
  }

  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(r(i) == r(j))continue;
      if(d[i][j] < 100){
	D[r(i)][r(j)] = 1;
	//cout << r(i) <<"->"<<r(j) << endl;
      }
    }
  }
  
  for(int i = 0;i < n;i++){
    topo(r(i));
    //cout << i << " " << r(i) << endl;
  }

  cout << 100 << " " << 3 <<" " << id.size() * 2 + 1 << endl;

  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 100;j++){
      cout << '#';
    }cout << endl;
  }
  cout << endl;
  for(int i = id.size() - 1;i >= 0;i--){
    int p = id[i];
    string hoge[3];
    for(int j = 0;j < 100;j++){
      hoge[0] += '.';
      hoge[1] += '.';
      hoge[2] += '.';
    }
    for(int j = 0;j < i;j++){
      if(D[id[i]][id[j]] == 0){
	hoge[0][4*j+3] = '#';
	hoge[0][4*j+5] = '#';
	hoge[1][4*j+4] = '#';
      }
    }
    int pos = 80;
    for(int j = 0;j < 10;j++){
      if(r(j) == id[i])hoge[0][pos++] = (char)('1' + j);
    }
    cout << hoge[0] << endl;
    cout << hoge[1] << endl;
    cout << hoge[2] << endl;
    cout << endl;
    for(int j = 0;j < 100;j++){
      hoge[0][j] = hoge[1][j] = hoge[2][j] = '#';
    }
    for(int j = 0;j < i;j++){
      hoge[0][4*j+4] = '.';
    }

    cout << hoge[0] << endl;
    cout << hoge[1] << endl;
    cout << hoge[2] << endl;
    cout << endl;
  }
  return 0;
}