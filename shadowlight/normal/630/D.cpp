#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
   long long n;
   cin >> n;
   long long k = 0;
   k = n * (n + 1) * 3 + 1;
   cout << k;
}