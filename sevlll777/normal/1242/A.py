n = int(input())
for i in range(2, int(n**0.5)+1):
    if n % i == 0:
        while n % i == 0:
            n //= i
        if n == 1:
            print(i)
        else:
            print(1)
        exit(0)
print(n)