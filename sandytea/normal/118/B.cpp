//program 118B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int N;cin>>N;
  if(N==2)
    {
      cout<<"    0"<<endl;
      cout<<"  0 1 0"<<endl;
      cout<<"0 1 2 1 0"<<endl;
      cout<<"  0 1 0"<<endl;
      cout<<"    0"<<endl;
    }
  if(N==3)
    {
      cout<<"      0"<<endl;
      cout<<"    0 1 0"<<endl;
      cout<<"  0 1 2 1 0"<<endl;
      cout<<"0 1 2 3 2 1 0"<<endl;
      cout<<"  0 1 2 1 0"<<endl;
      cout<<"    0 1 0"<<endl;
      cout<<"      0"<<endl;
    }
  if(N==4)
    {
      cout<<"        0"<<endl;
      cout<<"      0 1 0"<<endl;
      cout<<"    0 1 2 1 0"<<endl;
      cout<<"  0 1 2 3 2 1 0"<<endl;
      cout<<"0 1 2 3 4 3 2 1 0"<<endl;
      cout<<"  0 1 2 3 2 1 0"<<endl;
      cout<<"    0 1 2 1 0"<<endl;
      cout<<"      0 1 0"<<endl;
      cout<<"        0"<<endl;
    }
  if(N==5)
    {
      cout<<"          0"<<endl;
      cout<<"        0 1 0"<<endl;
      cout<<"      0 1 2 1 0"<<endl;
      cout<<"    0 1 2 3 2 1 0"<<endl;
      cout<<"  0 1 2 3 4 3 2 1 0"<<endl;
      cout<<"0 1 2 3 4 5 4 3 2 1 0"<<endl;
      cout<<"  0 1 2 3 4 3 2 1 0"<<endl;
      cout<<"    0 1 2 3 2 1 0"<<endl;
      cout<<"      0 1 2 1 0"<<endl;
      cout<<"        0 1 0"<<endl;
      cout<<"          0"<<endl;
    }
  if(N==6)
    {
      cout<<"            0"<<endl;
      cout<<"          0 1 0"<<endl;
      cout<<"        0 1 2 1 0"<<endl;
      cout<<"      0 1 2 3 2 1 0"<<endl;
      cout<<"    0 1 2 3 4 3 2 1 0"<<endl;
      cout<<"  0 1 2 3 4 5 4 3 2 1 0"<<endl;
      cout<<"0 1 2 3 4 5 6 5 4 3 2 1 0"<<endl;
      cout<<"  0 1 2 3 4 5 4 3 2 1 0"<<endl;
      cout<<"    0 1 2 3 4 3 2 1 0"<<endl;
      cout<<"      0 1 2 3 2 1 0"<<endl;
      cout<<"        0 1 2 1 0"<<endl;
      cout<<"          0 1 0"<<endl;
      cout<<"            0"<<endl;
    }
  if(N==7)
    {
      cout<<"              0"<<endl;
      cout<<"            0 1 0"<<endl;
      cout<<"          0 1 2 1 0"<<endl;
      cout<<"        0 1 2 3 2 1 0"<<endl;
      cout<<"      0 1 2 3 4 3 2 1 0"<<endl;
      cout<<"    0 1 2 3 4 5 4 3 2 1 0"<<endl;
      cout<<"  0 1 2 3 4 5 6 5 4 3 2 1 0"<<endl;
      cout<<"0 1 2 3 4 5 6 7 6 5 4 3 2 1 0"<<endl;
      cout<<"  0 1 2 3 4 5 6 5 4 3 2 1 0"<<endl;
      cout<<"    0 1 2 3 4 5 4 3 2 1 0"<<endl;
      cout<<"      0 1 2 3 4 3 2 1 0"<<endl;
      cout<<"        0 1 2 3 2 1 0"<<endl;
      cout<<"          0 1 2 1 0"<<endl;
      cout<<"            0 1 0"<<endl;
      cout<<"              0"<<endl;
    }
  if(N==8)
    {
      cout<<"                0"<<endl;
      cout<<"              0 1 0"<<endl;
      cout<<"            0 1 2 1 0"<<endl;
      cout<<"          0 1 2 3 2 1 0"<<endl;
      cout<<"        0 1 2 3 4 3 2 1 0"<<endl;
      cout<<"      0 1 2 3 4 5 4 3 2 1 0"<<endl;
      cout<<"    0 1 2 3 4 5 6 5 4 3 2 1 0"<<endl;
      cout<<"  0 1 2 3 4 5 6 7 6 5 4 3 2 1 0"<<endl;
      cout<<"0 1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 0"<<endl;
      cout<<"  0 1 2 3 4 5 6 7 6 5 4 3 2 1 0"<<endl;
      cout<<"    0 1 2 3 4 5 6 5 4 3 2 1 0"<<endl;
      cout<<"      0 1 2 3 4 5 4 3 2 1 0"<<endl;
      cout<<"        0 1 2 3 4 3 2 1 0"<<endl;
      cout<<"          0 1 2 3 2 1 0"<<endl;
      cout<<"            0 1 2 1 0"<<endl;
      cout<<"              0 1 0"<<endl;
      cout<<"                0"<<endl;
    }
  if(N==9)
    {
      cout<<"                  0"<<endl;
      cout<<"                0 1 0"<<endl;
      cout<<"              0 1 2 1 0"<<endl;
      cout<<"            0 1 2 3 2 1 0"<<endl;
      cout<<"          0 1 2 3 4 3 2 1 0"<<endl;
      cout<<"        0 1 2 3 4 5 4 3 2 1 0"<<endl;
      cout<<"      0 1 2 3 4 5 6 5 4 3 2 1 0"<<endl;
      cout<<"    0 1 2 3 4 5 6 7 6 5 4 3 2 1 0"<<endl;
      cout<<"  0 1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 0"<<endl;
      cout<<"0 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1 0"<<endl;
      cout<<"  0 1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 0"<<endl;
      cout<<"    0 1 2 3 4 5 6 7 6 5 4 3 2 1 0"<<endl;
      cout<<"      0 1 2 3 4 5 6 5 4 3 2 1 0"<<endl;
      cout<<"        0 1 2 3 4 5 4 3 2 1 0"<<endl;
      cout<<"          0 1 2 3 4 3 2 1 0"<<endl;
      cout<<"            0 1 2 3 2 1 0"<<endl;
      cout<<"              0 1 2 1 0"<<endl;
      cout<<"                0 1 0"<<endl;
      cout<<"                  0"<<endl;
    }
  return 0;
}