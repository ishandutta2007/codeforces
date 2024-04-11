#include <iostream> //scott so let's check if there are 3 distinct x and y, no two are equal, and middle isn't there ok

using namespace std; //demi

#include <algorithm> //scott 

int main()
{ //scott
  int x[9],y[9];
    for (int i = 0; i < 8; i++) cin >> x[i] >> y[i];
 //oh
bool bad = false;
for (int i = 0; i < 8; i++)
    for (int j = i + 1; j < 8; j++)
      if (x[i] == x[j] && y[i] == y[j])
        bad = true; // make new lists of sorted x and y and check that no pont matches both x[4] and y[4]?
 int nx[9],ny[9];
for (int i = 0; i < 8; i++)
    nx[i] = x[i], ny[i] = y[i];
sort(nx,nx+8),sort(ny,ny+8);
for (int i = 0; i < 8; i++)
  if (x[i] == nx[4] && y[i] == ny[4])
    bad = true;
int xc = 0, yc = 0;
for (int i = 0; i < 7; i++)
{ //scott
   xc += (nx[i] < nx[i+1]);
    if (ny[i] < ny[i+1]) yc++; //scott
}
bad |= !(xc == 2 && yc == 2); //scott
 cout<< ((bad) ? "ugly" : "respectable")<<endl;
return 0; //scott
}