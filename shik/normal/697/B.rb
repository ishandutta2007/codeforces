require 'bigdecimal'
x = BigDecimal.new(gets)
puts x == x.to_i ? x.to_i : x.to_s('F')