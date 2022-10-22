#include<stdio.h>
#include<stdlib.h>

int query(int c,int d){
  printf("? %d %d\n",c,d);
  fflush(stdout);
  int r;
  scanf("%d",&r);
  return r;
}

void answer(int a,int b){
  printf("! %d %d\n",a,b);
  fflush(stdout);
  return;
}

void run(void){
  int a=0;
  int b=0;
  const int empty=-10;
  int carry=empty;
  int i;
  for(i=29;i>=0;i--){
    int y=carry;
    carry=empty;
    if(y==empty){
      y=query(a,b);
    }
    if(y==0){
      y=query(a,b+(1<<i));
      if(y==1){
	a+=1<<i;
	b+=1<<i;
      }
    } else {
      int z=query(a+(1<<i),b+(1<<i));
      if(y!=z){
	if(y==1){
	  a+=1<<i;
	} else {
	  b+=1<<i;
	}
      } else {
	carry=z;
	y=query(a,b+(1<<i));
	if(y==1){
	  a+=1<<i;
	  b+=1<<i;
	}
      }
    }
  }
  answer(a,b);
  return;
}

int main(void){
  run();
  return 0;
}