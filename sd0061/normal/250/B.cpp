#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define N 100005
int l , t, a[9];
char s[N] ;

int main()
{
  cin >> t;
  int i , j , x , y ;
  while (t --)
  {
    x = 0 , y = 0;
    scanf("%s\n",s);
    l = strlen(s); 
    for (i = 0 ;i < l ;i ++)
      if (s[i] == ':')
        a[++ x] = i;  
     
    for (i = 1 ; i <= x ; i ++)
      if (a[i] - a[i - 1] > 1 || (a[i] == 1 && s[0] != ':')) 
        y ++;
    if (l - a[x] != 1)
      y ++;
       a[0] = -1;    
    for (i = 1 ; i <= x ; i ++)
    {
      if (a[i] - a[i - 1] == 5) 
      {
        for (j = a[i - 1] + 1 ; j < a[i] ;j ++)
          printf("%c",s[j]);
        printf(":");  
      }   
      if (a[i] - a[i - 1] == 4) 
      {
        printf("0");       
        for (j = a[i - 1] + 1 ; j < a[i] ;j ++)
          printf("%c",s[j]);
        printf(":");  
      }   
      if (a[i] - a[i - 1] == 3) 
      {
        printf("00");       
        for (j = a[i - 1] + 1 ; j < a[i] ;j ++)
          printf("%c",s[j]);
        printf(":");  
      }        
      if (a[i] - a[i - 1] == 2) 
      {
        printf("000");       
        for (j = a[i - 1] + 1 ; j < a[i] ;j ++)
          printf("%c",s[j]);
        printf(":");  
      }  
      if (a[i] - a[i - 1] == 1 && i != 1) 
      {
        y = 8 - y;
        for (j = 1 ;j < y ;j ++)
          printf("0000:");
        printf("0000");  
        if (i != x || l - a[x] != 1)
          printf(":");  
      }
    } 
    if (l - a[x] != 1)
    {
      if (l - a[x] == 5)  
      {
        for (j = a[x] + 1 ; j < l ;j ++)
          printf("%c",s[j]);            
      }   
      if (l - a[x] == 4)  
      {
        printf("0");    
        for (j = a[x] + 1 ; j < l ;j ++)
          printf("%c",s[j]);            
      }   
      if (l - a[x] == 3)  
      {
        printf("00");   
        for (j = a[x] + 1 ; j < l ;j ++)
          printf("%c",s[j]);            
      }   
      if (l - a[x] == 2)  
      {
        printf("000"); 
        for (j = a[x] + 1 ; j < l ;j ++)
          printf("%c",s[j]);            
      }   
      
    }
    printf("\n");
  }
  return 0;    
}