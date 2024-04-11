//At this point, I'm just throwing stuff at the wall and seeing what sticks.
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
  int len_s, len_t, q;
  cin >> len_s >> len_t >> q;
  char s[len_s+1];
  cin >> s;
  char t[len_t+1];
  cin >> t;
  
  //Already look for instances of t inside s
  bool locs[len_s];
  for (int i = 0; i <= len_s; i++) {
      int j = i;
      bool ok = true;
      for (int k = 0; k < len_t; k++) {
          if (s[j+k] != t[k]) {
              ok = false;
              break;
          }
      }
      locs[i] = ok;
  }
  
  //Queries
  for (int i = 0; i < q; i++) {
      int start, end, count = 0;
      cin >> start >> end;
      start--;
      for (int j = start; j <= end - len_t; j++) {
          count += locs[j];
      }
      cout << count << endl;
  }
}