t = int(input())
for i in range(t):
    n, a, b = list(map(int, input().split()))
    if a == 1:
        if (n-a)%b == 0:
            print("Yes");
        else:
            print("No")
    else:
        found = False
        mul = 1
        count = 0
        while mul <= n:
            if (n-mul)%b == 0:
                print("Yes")
                found = True
                break
            mul *= a
            count += 1
        if not found:
            print("No")