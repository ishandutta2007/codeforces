#include <cstdio>

using namespace std;

bool grid[3][3];
const int mx[4] = {-1, 0, 1, 0};
const int my[4] = {0, 1, 0, -1};
bool inr(int a, int b) {
    return a >= 0 && b >= 0 && a < 3 && b < 3;
}

void press(int x, int y) {
    if (inr(x, y)) grid[x][y] = !grid[x][y];
    for(int d = 0; d < 4; ++d)  {
    if (inr(x+ mx[d], y + my[d])) {
   grid[x+mx[d]][y+my[d]] = !grid[x + mx[d]][y + my[d]];
   }
   }
   }
   int main() {
   for(int i = 0; i < 3; ++i) {
   for(int j = 0; j < 3; ++j) {
   grid[i][j] = true;
   }
   }
   for(int i = 0; i < 3; ++i){ 
   for(int j = 0; j < 3; ++j) {
   int tmp;
   scanf("%d", &tmp);
   tmp %= 2;
   if (tmp) {
   press(i, j);
   }
   }
   }
   for(int i = 0; i < 3; ++i){ 
   for(int j = 0; j < 3; ++j) {
   printf("%d", grid[i][j]);
   }
   printf("\n");
   }
   return 0;
   }