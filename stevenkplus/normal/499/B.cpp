#include <map>
#include <iostream>
using namespace std;

map<string, string> mp;

int N, M;

int main() {
  cin >> N >> M;
  for(int i = 0; i < M; ++i) {
    string a, b;
    cin >> a >> b;
    if (b.size() < a.size()) mp[a] = b;
    else mp[a] = a;
  }

  for(int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    cout << mp[s] << " ";
  }
  cout << "\n";
}