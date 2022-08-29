package main

import "fmt"

func Main() (bool,int,int,int){
	var n int
	fmt.Scanf("%d\n",&n)
	on:=n
	var a=make([]struct{v,k int},30)
	t:=0
	for i:=2;i*i<=n;i++{
		if n%i==0{
			a[t].v=i
			a[t].k=0
			for n%i==0{
				n/=i
				a[t].k++
			}
			t++
		}
	}
	if n>1{
		a[t]=struct{v,k int}{n,1}
		t++
	}
	n=on
	if t==1{
		if a[0].k<=5{
			return false,0,0,0
		}
		return true,a[0].v,a[0].v*a[0].v,n/(a[0].v*a[0].v*a[0].v)
	}
	if t==2{
		if a[0].k+a[1].k<=3{
			return false,0,0,0
		}
		return true,a[0].v,a[1].v,n/(a[0].v*a[1].v)
	}
	return true,a[0].v,a[1].v,n/(a[0].v*a[1].v)
}

func main(){
	var t int
	fmt.Scanf("%d\n",&t)
	for ;t>0;t--{
		ok,a,b,c:=Main()
		if ok{
			fmt.Println("YES")
			fmt.Printf("%d %d %d\n",a,b,c)
		} else{
			fmt.Println("NO")
		}
	}
}