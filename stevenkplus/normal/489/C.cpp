#include <bits/stdc++.h>
using namespace std;

int main() {
int m, s;
cin >> m >> s;
if (m == 1 && s == 0) {
cout << "0 0\n";
return 0;
}
if (s < 1 || s > m * 9) {
cout << "-1 -1\n";
return 0;
}

{
if (s > (m - 1) * 9) {
cout << s - (m - 1) * 9;
for (int i = 0; i < m - 1; ++i) {
cout << 9;
}
cout << "\n";
} else {
cout << 1;
int nines = (s - 1) / 9;
int zeros = m - nines - 2;
int gap = (s - 1) % 9;
for(int i = 0; i < zeros; ++i) {
cout << 0;
}
cout << gap;
for (int i = 0; i < nines; ++i) {
cout << 9;
}
cout << "\n";
}

}

{
int nines = s / 9;
int gap = s % 9;
int zeros = m - nines - 1;
for (int i = 0; i < nines; ++i) {
cout << 9;
}
if (zeros >= 0) cout << gap;
for (int i = 0; i < zeros; ++i) {
cout << 0;
}
cout << "\n";
}

}