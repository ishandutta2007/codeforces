def prigskok(a, b, k):
    return (a-b)*(k//2)+a*(k%2)


for t in range(int(input())):
    a, b, k = map(int, input().split())
    print(prigskok(a, b, k))