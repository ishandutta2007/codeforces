t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    answer = (1 << 30) - 1
    for i in range(n):
        if a[i] != i:
            answer = answer & a[i]
    print(answer)