package main

import "fmt"

func check(a,b,c,n int) bool{
	n+=a+b+c
	if n%3!=0 {
		return false
	}
	if a>n/3 || b>n/3 ||c>n/3{
		return false
	}
	return true
}

func work(){
	var a,b,c,n int
	fmt.Scanf("%d %d %d %d\n",&a,&b,&c,&n);
	if check(a,b,c,n){
		fmt.Println("YES")
	} else { 
		fmt.Println("NO")
	}
}

func main(){
	var t int
	fmt.Scanf("%d\n",&t)
	for ;t>0;t--{
		work()
	}
}