#include <iostream>
using namespace std;

int main() {
int x,y,d; cin>>x>>y>>d;
int a[x * y];
for (int i = 0; i < x*y; i++) {
cin>>a[i];}
int cnts[100000] = {0};
for (int i = 0; i < x*y; i++) {
cnts[a[i]]++;}
int med = 0, below = 0;
while (1) {
below += cnts[med];
if(below*2>=x*y) break;
else ++med;}
int sum = 0;
for(int i = 0; i < x * y; i++) { 
int diff = a[i]-med;
if (diff < 0) diff = diff * -1;
if(diff % d != 0) {
sum = -1; break;
}
sum += diff / d;}
cout << sum << endl;
return 0;
}