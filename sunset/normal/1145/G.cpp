#include <bits/stdc++.h>

using namespace std;

int main() {
  cout << "R" << endl;
  cout << "R" << endl;
  cout << "S" << endl;
  cout << "S" << endl;
  cout << "P" << endl;
  cout << "P" << endl;
  cout << "R" << endl;
  vector<string> verd(7);
  for (int i = 0; i < 7; ++i) {
    cin >> verd[i];
  }
  map<char, char> to;
  if (verd[1] == "player") {
    to['R'] = 'R';
  } else if (verd[2] == "player") {
    to['R'] = 'S';
  } else {
    to['R'] = 'P';
  }
  if (verd[3] == "player") {
    to['S'] = 'S';
  } else if (verd[4] == "player") {
    to['S'] = 'P';
  } else {
    to['S'] = 'R';
  }
  if (verd[5] == "player") {
    to['P'] = 'P';
  } else if (verd[6] == "player") {
    to['P'] = 'R';
  } else {
    to['P'] = 'S';
  }
  char cur = 'P';
  for (int i = 0; i < 13; ++i) {
    cur = to[cur];
    cout << cur << endl;
  }
  return 0;
}