from math import factorial
n = int(input())
n -= 1
print(factorial(2 * n) // factorial(n) // factorial(n))