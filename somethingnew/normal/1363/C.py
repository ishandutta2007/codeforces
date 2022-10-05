for t in range(int(input())):
    n, x = map(int,input().split())
    nm = 0
    for i in range(n - 1):
        a,b = map(int,input().split())
        if a == x: nm += 1
        elif b == x: nm += 1
    if nm < 2:
        print("Ayush")
    else:
        if n % 2:
            print("Ashish")
        else:
            print("Ayush")