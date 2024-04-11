package main

import "fmt"

type atom struct{x,y int}

func Main(){
	var n int
	fmt.Scanf("%d\n",&n)
	a:=make([]atom,n)
	for i:=0;i<n;i++{
		var x,y int
		fmt.Scanf("%d %d\n",&x,&y)
		a[i]=atom{x,y}
	}
	for rd:=0;rd<n;rd++{
		for i:=0;i+1<n;i++{
			if a[i].x+a[i].y>a[i+1].x+a[i+1].y{
				a[i],a[i+1]=a[i+1],a[i]
			}
		}
	}
	nowx,nowy:=0,0
	for i:=0;i+1<n;i++{
		if a[i].x>a[i+1].x || a[i].y>a[i+1].y{
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
	for i:=0;i<n;i++{
		for ;nowx<a[i].x;nowx++{
			fmt.Print("R")
		}
		for ;nowy<a[i].y;nowy++{
			fmt.Print("U")
		}
	}
	fmt.Print("\n")
}

func main(){
	var t int
	fmt.Scanf("%d\n",&t)
	for ;t>0;t--{
		Main()
	}
}