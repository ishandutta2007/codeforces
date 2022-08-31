#include <cstdio> //Richard: I don't get first sample
#include <iostream> //scott so this is just brute force, N^2 check all possible vals of ans
#include <cstring> //Richard: I think you can just take min over max of all neighboring pairs?
#include <algorithm> //scott that suonds complicated also i did the hard version of this which is nlogn with bin search so i think this is the way to go
using namespace std; //Richard: ok, let's brute force then

int N; //scott so we just need N and arr[1100] as vars i think
int arr[1100]; //yeah, need function fo what's reachable though

bool works (int t) { //scott check if day t works so we just need a cur loc and a while loop to do this i think
  int canWork[1100]; //richard, ok, loop up this
    int cloc = 0; //scott your arr is not necessary so like we just need to do if (arr[cloc+1] >= t) cloc++ and same for cloc+2 right
  if(arr[0] < t) return false; //richard: is false ok?
  if (arr[N-1] < t) return false; //scott yeah sounds good
  while(cloc < N - 1) { //richard: ok, do the transition magic
    if (cloc + 2 <= N - 1 && arr[cloc+2] >= t) // scott
      cloc += 2;
    else if (arr[cloc+1] >= t) //scott
      cloc ++;
    else //scott return false right?
      return false; //richard yeah...
  }//scott
  return true; //richard
} //scott now main

int main() { //richard
  cin >> N; //scott
  for(int i = 0; i < N; ++i) cin >> arr[i]; //richard
  for (int i = 1; i <= 1001; i++) //scott so if !works (i) we give i-1?
    if(!works(i)) { //richard
      cout << i - 1 << "\n"; //scott
      return 0; //richard
    }//scott any chance of this not catching?
  return 0; //richard meh who cares
} //scott