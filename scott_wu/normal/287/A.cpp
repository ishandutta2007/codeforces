#include <iostream>
#include<cstring>
#include <algorithm>

using namespace std;

bool board[5][5];

bool good()
{
    for (int i = 0; i <3; i ++)
      for (int j = 0; j < 3; j++)
      {
            if (board[i][j] == board[i+1][j] && board[i+1][j] == board[i][j+1] && board[i][j+1] == board[i+1][j+1])
              return 1;
            }return false;
        }
int main()
{
    char c;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
      {
         cin>>c;
         board[i][j] = (c == '.');
      }
    
    bool works = good();
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
          board[i][j]^=1,works|=good(),board[i][j]^=1;
    cout << ((works) ? "YES\n" : "NO\n");
    return 0;
}