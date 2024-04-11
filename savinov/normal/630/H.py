from math import *

n = int(raw_input())

print factorial(n) / factorial(n - 5) / factorial(5) * factorial(n) / factorial(n - 5)