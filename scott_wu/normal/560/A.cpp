#include <iostream>

using namespace std;

int main()
{

int N; cin >> N;
bool x = false;
for (int i = 0; i < N; i++)
{
int c; cin >> c;
if (c == 1) x = true;
}

if (x) cout << "-1\n";
else cout << "1\n";
return 0;
}