#include <vector>
#include <cstdio>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
#define sz(x) int((x).size())

vector<int> A, B, C;

int N;
int main () {
scanf("%d", &N);
for(int i = 0; i < N; ++i) {
int tmp;
scanf("%d", &tmp);
if (tmp < 0) A.push_back(tmp);
else if (tmp > 0) B.push_back(tmp);
else C.push_back(tmp);
}
if (!sz(B)) {
B.push_back(A.back());
A.pop_back();
B.push_back(A.back());
A.pop_back();
}
if (sz(A) % 2 == 0) {
C.push_back(A.back());
A.pop_back();
}
printf("%d", sz(A));
repi(i, A) printf(" %d", *i);
printf("\n");
printf("%d", sz(B));
repi(i, B) printf(" %d", *i);
printf("\n");
printf("%d", sz(C));
repi(i, C) printf(" %d", *i);
printf("\n");
return 0;
}