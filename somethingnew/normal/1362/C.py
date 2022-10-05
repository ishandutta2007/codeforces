lst = [0] * 80
lst[0] = 1
for i in range(1, 80):
    lst[i] = lst[i - 1] * 2 + 1
for t in range(int(input())):
    n = int(input())
    ans = 0
    i = 0
    while n:
        if n % 2 == 1:
            ans += lst[i]
        i += 1
        n //= 2
    print(ans)