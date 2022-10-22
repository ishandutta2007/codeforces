#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

int n ,m;
int main()
{
  cin >> n >> m;
  cout << ((n * m) >> 1); 
  return 0;
}