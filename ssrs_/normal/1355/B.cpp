#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int N;
    cin >> N;
    vector<int> e(N);
    for (int j = 0; j < N; j++){
      cin >> e[j];
    }
    sort(e.begin(), e.end());
    int count = 0;
    int people = 0;
    for (int j = 0; j < N; j++){
      people++;
      if (e[j] <= people){
        count++;
        people = 0;
      }
    }
    cout << count << endl;
  }
}