#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T;
  cin>>T;
  for (int tt=0; tt<T; tt++) {
    int counts[26]={0};
    string word;
    cin>>word;
    for (char &c:word)
      counts[c-'a']++;
    
    string toPrint;
    bool possible=true;
    
    vector<int> letters;
    for (int i=0; i<26; i++)
      if (counts[i]) letters.push_back(i);

    if (letters.size()==2&&letters[0]+1==letters[1]) {
      possible=false;
    }
    if (letters.size()==3&&letters[0]+1==letters[1]&&letters[0]+2==letters[2]) {
      possible=false;
    }

    if (possible && letters.size()==3) {
      if (letters[0]+1==letters[1]) {
        for (int i=0; i<counts[letters[0]]; i++)
          toPrint.push_back('a'+letters[0]);
        for (int i=0; i<counts[letters[2]]; i++)
          toPrint.push_back('a'+letters[2]);
        for (int i=0; i<counts[letters[1]]; i++)
          toPrint.push_back('a'+letters[1]);
      }
      else {
        for (int i=0; i<counts[letters[2]]; i++)
          toPrint.push_back('a'+letters[2]);
        for (int i=0; i<counts[letters[0]]; i++)
          toPrint.push_back('a'+letters[0]);
        for (int i=0; i<counts[letters[1]]; i++)
          toPrint.push_back('a'+letters[1]);
        
      }
    }
    else if (possible) {
      for (int i=1; i<letters.size(); i+=2) {
        for (int j=0; j<counts[letters[i]]; j++)
          toPrint.push_back('a'+letters[i]);
      }
      for (int i=0; i<letters.size(); i+=2) {
        for (int j=0; j<counts[letters[i]]; j++)
          toPrint.push_back('a'+letters[i]);
      }
    }

    if (possible) {
      cout<<toPrint<<'\n';
    }
    else {
      cout<<"No answer\n";
    }
  }
  
  return 0;
}