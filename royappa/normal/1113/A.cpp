#include <bits/stdc++.h>
using namespace std;

int main() {
int n, v;
cin >> n >> v;
if (n-1 <= v) {
   cout << n-1 << endl;
   exit(0);
}

int cost = 0;
int tank = 0;
int i = 1;
while (i+tank < n) {
    int k = min(v-tank, (n-1)-tank);
    cost += i*k;
    tank += k;
    i++;
    tank--;
}
cout << cost << endl;
exit(0);

}