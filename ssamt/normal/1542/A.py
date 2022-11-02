t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    count = 0
    for x in a:
        if x%2 == 1:
            count += 1
    if count == n:
        print("Yes")
    else:
        print("No")